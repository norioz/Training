using Microsoft.Azure.Documents.Client;
using System;
using System.Configuration;
using KeyVault;

namespace Repository
{
    public class CosmosDBRepository
    {
        private static DocumentClient documentClient;
        private IKeyVaultManager keyVaultManager;

        private static readonly object syncRoot = new Object();
        protected CosmosDBRepository(IKeyVaultManager keyVaultManager)
        {
            this.keyVaultManager = keyVaultManager;
        }
        public DocumentClient DocumentClient
        {
            get
            {
                if (documentClient == null)
                {
                    lock (syncRoot)
                    {
                        if (documentClient == null)
                        {
                            documentClient = new DocumentClient(new Uri(ConfigurationManager.AppSettings["CosmosDbUrl"]), keyVaultManager.GetSecret<string>("DocumentDBPrimaryKey"), new ConnectionPolicy
                            {
                                ConnectionMode = ConnectionMode.Direct,
                                ConnectionProtocol = Protocol.Tcp,
                                MaxConnectionLimit = 500,
                            });
                        }
                    }
                }
                documentClient.OpenAsync().Wait();
                return documentClient;
            }
        }
    }
}
