using System;
using System.Net.Http;
using Microsoft.IdentityModel.Clients.ActiveDirectory;
using System.Net.Http.Headers;
using Microsoft.VisualStudio.TestTools.WebTesting;
using System.ComponentModel;

namespace PE.PerformanceTest.WebTestPlugIn
{

    [Description("This plugin can be used to set the Authentication request properties for the validations")]
    public class AuthWebTestPlugin : WebTestPlugin
    {
        private string aadInstance = string.Empty;
        private string tenantId = string.Empty;
        private string authority = string.Empty;
        private string appId = string.Empty;
        private string clientId = string.Empty;
        private string clientSecret = string.Empty;

        /// <summary>
        /// This plugin generates authentication toke for API web test.
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        public override void PreWebTest(object sender, PreWebTestEventArgs e)
        {
            HttpClient httpClient = new HttpClient();
            AuthenticationContext authContext = new AuthenticationContext(authority);

            try
            {
                ClientCredential clientCredential = new ClientCredential(clientId, clientSecret);
                var result = authContext.AcquireTokenAsync(appId, clientCredential).Result;
                httpClient.DefaultRequestHeaders.Authorization = new AuthenticationHeaderValue("Bearer", result.AccessToken);
                e.WebTest.Context["token"] = httpClient.DefaultRequestHeaders.Authorization;
            }

            catch (Exception)
            {
                // ignored
            }
        }
    }
}

