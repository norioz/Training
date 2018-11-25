namespace KeyVault
{
    public interface IKeyVaultManager
    {
        /// <summary>
        /// Get secret value for given secret name
        /// </summary>
        /// <typeparam name="T"></typeparam>
        /// <param name="secretName"></param>
        /// <returns></returns>
        T GetSecret<T>(string secretName) where T : class;

        /// <summary>
        /// Retrive all the secrets in keyvault
        /// </summary>
        void GetAllSecrets();
    }
}