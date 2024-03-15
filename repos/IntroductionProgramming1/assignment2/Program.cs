namespace Assignment2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Enter your age: ");

            Console.WriteLine("Next year you will be " + (int.Parse(Console.ReadLine()) + 1) + " years old.");
        }
    }
}