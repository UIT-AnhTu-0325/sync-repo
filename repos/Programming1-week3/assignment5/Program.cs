namespace assignment5
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Enter first number: ");
            int number1 = int.Parse(Console.ReadLine());
            Console.Write("Enter second number: ");
            int number2 = int.Parse(Console.ReadLine());

            if (number1 % number2 == 0) 
            {
                Console.WriteLine("Number 1 is multiple of number 2");
            }
            else if (number2 % number1 == 0)
            {
                Console.WriteLine("Number 2 is multiple of number 1");
            }
            else
            {
                Console.WriteLine("Numbers are no multiples");
            }
        }
    }
}