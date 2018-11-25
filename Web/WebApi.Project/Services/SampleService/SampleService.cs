using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Net;
using System.Threading.Tasks;
using System.Web.Http;
using System.Web.Http.Description;

namespace WebApi.Project.Services.SampleService
{
    public class SampleService : ISampleService
    {
        public Task<Sample> Add(Sample sample)
        {
            return Task.FromResult(new Sample { Id = new Random().Next(), Value = sample.Value });
        }

        public Task<Sample> Get(int id)
        {
            return Task.FromResult(new Sample { Id = id, Value = "Finance" });
        }

        public Task<IEnumerable<Sample>> Get()
        {
            return Task.FromResult<IEnumerable<Sample>>(new List<Sample>
            {
                new Sample {Id = 1, Value = "Finance"},
                new Sample {Id = 2, Value = "Legal"}
            });
        }

        public Task Update(Sample sample)
        {
            return Task.CompletedTask;
        }

        public Task Delete(int id)
        {
            return Task.CompletedTask;
        }
    }
}