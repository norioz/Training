using System;
using System.Configuration;
using Microsoft.Azure.KeyVault;
using System.Collections.Generic;
using Microsoft.Azure.Services.AppAuthentication;


namespace KeyVault
{
    /// <summary>
    /// Class to access keyvault secrets
    /// </summary>
    public class KeyVaultManager : IKeyVaultManager
    {
        private readonly KeyVaultClient _keyVaultClient;
        /// <summary>
        /// Get all the secrets
        /// </summary>
        public Dictionary<string, string> Secrets { get; set; }

        public KeyVaultManager()
        {
            Secrets = new Dictionary<string, string>();
            AzureServiceTokenProvider azureServiceTokenProvider = new AzureServiceTokenProvider();
            _keyVaultClient = new KeyVaultClient(new KeyVaultClient.AuthenticationCallback(azureServiceTokenProvider.KeyVaultTokenCallback));
        }

        /// <summary>
        /// Get secret value for given secret name
        /// </summary>
        /// <typeparam name="T"></typeparam>
        /// <param name="secretName"></param>
        /// <returns></returns>
        public T GetSecret<T>(string secretName) where T : class
        {
            T returnValue = null;
            try
            {
                var value = _keyVaultClient.GetSecretAsync(ConfigurationManager.AppSettings["KeyVaultUrl"], secretName)?.Result;
                if (value != null)
                {
                    returnValue = value.Value as T;
                    if (returnValue == null)
                    {
                    }
                }
            }
            catch (Exception ex)
            {
                //Log to telemetry
            }

            return returnValue;
        }

        /// <summary>
        /// Retrive all the secrets in keyvault
        /// </summary>
        public void GetAllSecrets()
        {
            var configNames = _keyVaultClient.GetSecretsAsync(ConfigurationManager.AppSettings["KeyVaultUrl"], 25)?.Result;
            foreach (var configName in configNames)
            {
                var configValue = _keyVaultClient.GetSecretAsync(ConfigurationManager.AppSettings["KeyVaultUrl"], configName.Identifier.Name)?.Result;
                if (configValue != null)
                {
                    Secrets.Add(configName.Identifier.Name, configValue.Value);
                }
            }
        }

    }
}
