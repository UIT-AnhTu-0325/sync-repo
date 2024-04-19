using System.Globalization;

namespace portalservice.Middleware;

public class LocalizationMiddleware
{
    private readonly RequestDelegate _next;

    public LocalizationMiddleware(RequestDelegate next)
    {
        _next = next;
    }
    
    public async Task Invoke(HttpContext context)
    {
        var lang = context.Request.Headers.AcceptLanguage.ToString();
        if (string.IsNullOrEmpty(lang))
        {
            lang = "en";
        }

        CultureInfo.CurrentCulture = new CultureInfo(lang);
        CultureInfo.CurrentUICulture = new CultureInfo(lang);

        await _next(context);
    }
}