using System.Configuration;
using Microsoft.Owin;
using Owin;
using WebApi.Project.App_Start;
using KeyVault;

[assembly: OwinStartup(typeof(WebApi.Project.Startup))]
namespace WebApi.Project
{
    /// <summary>
    /// Represents the entry point into an application.
    /// </summary>
    public class Startup
    {
        /// <summary>
        /// Specifies how the ASP.NET application will respond to individual HTTP request.
        /// </summary>
        /// <param name="app">Instance of <see cref="IAppBuilder"/>.</param>
        public void Configuration(IAppBuilder app)
        {
            new ApiConfig(app)
                .ConfigureCorsMiddleware(ConfigurationManager.AppSettings["cors"])
                .ConfigureAufacMiddleware()
                .ConfigureFormatters()
                .ConfigureRoutes()
                .ConfigureExceptionHandling()
                .ConfigureSwagger()
                .UseWebApi();
        }

        /// <summary>
        /// use below code as needed
        /// </summary>
        public void RetrieveSecrets()
        {
            // I put my GetToken method in a Utils class. Change for wherever you placed your method.
            var kv = new KeyVaultManager();
            kv.GetAllSecrets();

            //Get particular secret
            var value = kv.GetSecret<string>(ConfigurationManager.AppSettings["SecretName"]);
        }
    }
}