using System;
using System.Collections.Generic;
using System.Net;
using System.Threading.Tasks;
using System.Web.Http;
using System.Web.Http.Description;
using Swashbuckle.Examples;
using WebApi.Project.Services.SampleService;

namespace WebApi.Project.Controllers
{
    /// <summary>
    /// Represents test controller that should be removed.
    /// </summary>
    [RoutePrefix("api/sample")]

    public class SampleController : ApiController
    {
        private readonly ISampleService _service;

        public SampleController(ISampleService service)
        {
            _service = service;
        }

        /// <summary>
        /// Tries to create a new sample.
        /// </summary>
        /// <param name="sample">Instance of <see cref="Sample"/>.</param>
        /// <returns>Returns 201.</returns>
        [HttpPost, Route(""), ResponseType(typeof(Sample))]
        [SwaggerRequestExample(typeof(Sample), typeof(SampleRequest))]
        [SwaggerResponseExample(HttpStatusCode.Created, typeof(SampleResponse))]
        public async Task<IHttpActionResult> Post(Sample sample)
        {
            var newSample = await _service.Add(sample).ConfigureAwait(false);

            return CreatedAtRoute("GetById", new { newSample.Id }, newSample);
        }

        /// <summary>
        /// Tries to retrieve all sample objects.
        /// </summary>
        /// <returns>200 with collection of sample objects.</returns>
        [HttpGet, Route(""), ResponseType(typeof(IEnumerable<Sample>))]
        [SwaggerResponseExample(HttpStatusCode.OK, typeof(SampleListResponse))]
        public async Task<IHttpActionResult> Get()
        {
            var samples = await _service.Get().ConfigureAwait(false);

            return Ok(samples);
        }

        /// <summary>
        /// Tries to retrieve specified sample.
        /// </summary>
        /// <param name="id">Unique identifier.</param>
        /// <returns>200, or 404 if the sample doesn't exist.</returns>
        [HttpGet, Route("{id:int}", Name = "GetById"), ResponseType(typeof(Sample))]
        [SwaggerResponseExample(HttpStatusCode.OK, typeof(SampleResponse))]
        public async Task<IHttpActionResult> Get(int id)
        {
            var sample = await _service.Get(id).ConfigureAwait(false);

            if (sample == null)
                return NotFound();

            return Ok(sample);
        }

        /// <summary>
        /// Tries to update the sample object.
        /// </summary>
        /// <param name="sample">Instance of <see cref="Sample"/> that contains modified values.</param>
        /// <returns>200.</returns>
        [HttpPatch, Route("")]
        [SwaggerRequestExample(typeof(Sample), typeof(SampleRequest))]
        public async Task<IHttpActionResult> Patch(Sample sample)
        {
            await _service.Update(sample).ConfigureAwait(false);

            return Ok();
        }

        /// <summary>
        /// Tries to delete the specified sample.
        /// </summary>
        /// <param name="id">Unique identifier.</param>
        /// <returns>200.</returns>
        [HttpDelete, Route("{id:int}")]
        public async Task<IHttpActionResult> Delete(int id)
        {
            // Delete should throw 404 if the resource doesn't exist, but it's skipped for brevity sake.
            await _service.Delete(id).ConfigureAwait(false);

            return Ok();
        }
    }
}