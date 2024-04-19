using Microsoft.AspNetCore.Mvc;
using Microsoft.Extensions.Localization;
using portalservice.Helper;

namespace portalservice.Controllers
{
    [ApiController]
    [Route("[controller]")]
    public class WeatherForecastController : ControllerBase
    {
        private static readonly string[] Summaries = new[]
        {
            "Freezing", "Hot", "Chilly"
        };

        private readonly ILogger<WeatherForecastController> _logger;

        public WeatherForecastController(ILogger<WeatherForecastController> logger)
        {
            _logger = logger;
        }

        [HttpGet(Name = "GetWeatherForecast")]
        public IEnumerable<WeatherForecast> Get()
        {
            var loc = new CustomStringLocalizer();

            return Enumerable.Range(1, 5).Select(index => new WeatherForecast
                {
                    Date = DateTime.Now.AddDays(index),
                    TemperatureC = Random.Shared.Next(-20, 55),
                    Summary = loc[Summaries[Random.Shared.Next(Summaries.Length)]]
                })
                .ToArray();
        }
    }
}