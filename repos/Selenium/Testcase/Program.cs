using OpenQA.Selenium.Chrome;
using OpenQA.Selenium;

namespace Testcase
{
    internal class Program
    {
        static void Main(string[] args)
        {
            IWebDriver driver = new ChromeDriver();
            driver.Navigate().GoToUrl("https://selenium.dev");
        }
    }
}