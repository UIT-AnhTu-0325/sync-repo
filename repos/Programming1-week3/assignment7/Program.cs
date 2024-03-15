namespace assignment7
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Enter weight (kg): ");
            int weight = int.Parse(Console.ReadLine());
            Console.Write("Enter length (cm): ");
            int length = int.Parse(Console.ReadLine());
            Console.Write("Enter gender (male/female): ");
            string gender = Console.ReadLine();

            double height = length * length / 10000.0;
            double bmi = Math.Round((double) weight / height, 1);
            double start, end;

            Console.WriteLine();
            Console.WriteLine($"bmi-values: {bmi}");
            if (gender == "male")
            {
                Console.WriteLine("normal bmi-values (min .. max): 20..25");
                start = Math.Round(20 * height, 1);
                end = Math.Round(25 * height, 1);
            }
            else
            {
                Console.WriteLine("normal bmi-values (min .. max): 19..24");
                start = Math.Round(19 * height, 1);
                end = Math.Round(24 * height, 1);
            }
            Console.WriteLine($"healthy weight range: {start} .. {end}");
        }
    }
}