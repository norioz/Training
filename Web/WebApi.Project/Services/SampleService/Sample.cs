using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace WebApi.Project.Services.SampleService
{
    public class Sample
    {
        /// <summary>
        /// Gets the creation date.
        /// </summary>
        public DateTime CreatedAt => DateTime.UtcNow;

        /// <summary>
        /// Gets or sets the unique identifier.
        /// </summary>
        public int Id { get; set; }

        /// <summary>
        /// Gets or sets the value.
        /// </summary>
        public object Value { get; set; }
    }
}