using System.Globalization;
using Microsoft.Extensions.Localization;

namespace portalservice.Helper;

public class CustomStringLocalizer : IStringLocalizer
{
    private const string key1 = "Freezing";
    private const string key2 = "Hot";
    private const string key3 = "Chilly";

    private readonly Dictionary<string, Dictionary<string, string>> _resource;

    private readonly Dictionary<string, string> enResource = new()
    {
        { key1, "en_Freezing" },
        { key2, "en_Hot" },
        { key3, "en_Chilly" }
    };

    private readonly Dictionary<string, string> viResource = new()
    {
        { key1, "vi_Freezing" },
        { key2, "vi_Hot" },
        { key3, "vi_Chilly" }
    };

    public CustomStringLocalizer()
    {
        _resource = new Dictionary<string, Dictionary<string, string>>
        {
            { "en", enResource },
            { "vi", viResource }
        };
    }

    public IEnumerable<LocalizedString> GetAllStrings(bool includeParentCultures)
    {
        var curCulture = includeParentCultures
            ? CultureInfo.GetCultures(CultureTypes.AllCultures)
            : CultureInfo.GetCultures(CultureTypes.SpecificCultures);

        return _resource
            .Where(x => curCulture
                .Select(z => z.TwoLetterISOLanguageName)
                .Contains(x.Key))
            .SelectMany(x => x.Value
                .Select(y => new LocalizedString(y.Key, y.Value)));
    }

    private LocalizedString GetString(string name, params object[] args)
    {
        var curLang = CultureInfo.CurrentCulture.TwoLetterISOLanguageName;
        if (!_resource.TryGetValue(curLang, out var items)
            || !items.TryGetValue(name, out var outStr))
            return new LocalizedString(name, name, true);
        var ans = string.Format(outStr, args);
        return new LocalizedString(name, ans);
    }

    public LocalizedString this[string name] => GetString(name);

    public LocalizedString this[string name, params object[] arguments] => GetString(name, arguments);
}