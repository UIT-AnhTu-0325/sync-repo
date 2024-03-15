namespace assignment1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int highest, lowest;
            Console.Write("Enter first number: ");
            int number1 = int.Parse(Console.ReadLine());
            Console.Write("Enter second number: ");
            int number2 = int.Parse(Console.ReadLine());

            if (number1 > number2) {
                highest = number1;
                lowest = number2;
            }   
            else
            {
                highest = number2;
                lowest = number1;
            }

            Console.WriteLine();
            Console.WriteLine("highest number is: " + highest);
            Console.WriteLine("lowest number is: " + lowest);

        }
    }
}