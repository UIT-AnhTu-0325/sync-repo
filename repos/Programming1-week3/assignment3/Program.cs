namespace assignment3
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Enter first number: ");
            int number1 = int.Parse(Console.ReadLine());
            Console.Write("Enter second number: ");
            int number2 = int.Parse(Console.ReadLine());
            Console.Write("Enter third number: ");
            int number3 = int.Parse(Console.ReadLine());

            if (number3 < number1 && number3 < number2)
            {
                Console.WriteLine("The third number is the smallest of the three");
            }
            else
            {
                Console.WriteLine("The third number is not the smallest of the three");
            }
        }
    }
}