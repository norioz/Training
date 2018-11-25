using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using Swashbuckle.Examples;

namespace WebApi.Project.Services.SampleService
{
    public class SampleListResponse : IExamplesProvider
    {
        public object GetExamples()
        {
            return new List<Sample>
            {
                new Sample {Id = new Random().Next(), Value = Guid.NewGuid().ToString().Remove(6)},
                new Sample {Id = new Random().Next(), Value = Guid.NewGuid().ToString().Remove(6)}
            };
        }
    }
}