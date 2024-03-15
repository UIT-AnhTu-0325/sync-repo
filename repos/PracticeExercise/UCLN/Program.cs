namespace UCLN
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Enter first number: ");
            int input1 = int.Parse(Console.ReadLine());
            Console.Write("Enter second number: ");
            int input2 = int.Parse(Console.ReadLine());

            var result = GCD(input1, input2);
            Console.WriteLine($"The greatest common divisor is {result}");
        }
        static int GCD(int num1, int num2)
        {
            int ucln = int.MinValue;

            for (int i = 1; i <= num1; i++)
            {
                if (num1 % i == 0 && num2 % i == 0)
                {
                    ucln = i;
                }
            }
            return ucln;
        }
    }
}