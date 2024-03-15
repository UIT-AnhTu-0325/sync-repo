namespace assignment2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Enter 1st number: ");
            float input1 = float.Parse(Console.ReadLine());
            Console.Write("Enter 2nd number: ");
            float input2 = float.Parse(Console.ReadLine());
            Console.Write("Enter 3rd number: ");
            float input3 = float.Parse(Console.ReadLine());

            float average = (input1 + input2 + input3) / 3;
            Console.WriteLine("The average is: " + average);
        }
    }
}