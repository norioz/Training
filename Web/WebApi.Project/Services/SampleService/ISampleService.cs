using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WebApi.Project.Services.SampleService
{
    public interface ISampleService
    {
        Task<Sample> Add(Sample sample);

        Task<Sample> Get(int id);

        Task<IEnumerable<Sample>> Get();

        Task Update(Sample sample);

        Task Delete(int id);
    }
}
