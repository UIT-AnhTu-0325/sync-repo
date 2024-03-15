namespace BCNN
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Enter first number: ");
            int input1 = int.Parse(Console.ReadLine());
            Console.Write("Enter second number: ");
            int input2 = int.Parse(Console.ReadLine());

            var result = LCM(input1, input2);
            Console.WriteLine($"The lowest common multiple is {result}");
        }
        static int LCM(int num1, int num2)
        {
            int lcm = num1;
            while (lcm % num1 != 0 || lcm % num2 != 0)
            {
                lcm++;
            }
            return lcm;
        }
    }
}