namespace Assignment3
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Enter your first name: ");
            string firstName = Console.ReadLine();

            Console.Write("Enter your last name: ");
            string lastName = Console.ReadLine();

            //Display full name (option 1)
            Console.WriteLine("Your full name is " + firstName + " " + lastName);

            //Display full name (option 2)
            Console.WriteLine("Your full name is {0} {1}", firstName, lastName);

            //Display full name (option 3 - string interpolation)
            Console.WriteLine($"Your full name is {firstName} {lastName}");
        }
    }
}