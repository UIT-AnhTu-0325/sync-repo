namespace assignment8
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Enter number of working hours: ");
            int hours = int.Parse(Console.ReadLine());
            Console.Write("Enter number of years: ");
            int years = int.Parse(Console.ReadLine());
            Console.Write("Enter number of failures: ");
            int fails = int.Parse(Console.ReadLine());

            if (hours > 10000 || years > 6 || fails > 25)
            {
                Console.WriteLine("Machine needs to be replaced.");
            }
            else
            {
                Console.WriteLine("Machine does not need to be replaced.");
            }
        }
    }
}