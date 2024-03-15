namespace SoChinhPhuong
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Enter a number: ");
            int input = int.Parse(Console.ReadLine());

            var result = PerfectSquare(input);
            if (result == true)
            {
                Console.WriteLine($"{input} is perfect square");
            }
            else
            {
                Console.WriteLine($"{input} is not perfect square");
            }
        }
        static bool PerfectSquare (int input)
        {
            for (int i = 1; i * i <= input; i++)
            {
                int value = i * i;

                if (value == input)
                {
                    return true;
                }
            }
            return false;
        }
    }
}