using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using Swashbuckle.Examples;

namespace WebApi.Project.Services.SampleService
{
    public class SampleResponse : IExamplesProvider
    {
        public object GetExamples()
        {
            return new Sample
            {
                Id = new Random().Next(),
                Value = Guid.NewGuid().ToString().Remove(6)
            };
        }
    }
}