namespace assignment1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.Write("enter your name: ");
            string name = Console.ReadLine();
            Console.Write("enter your year of birth: ");
            int year = int.Parse(Console.ReadLine());
            Console.Write("enter your age: ");
            int age = int.Parse(Console.ReadLine());

            int currentYear = DateTime.Now.Year;
            int nowAge = currentYear - year;

            if (nowAge == age - 1)
            {
                Console.WriteLine($"Hi {name}, your birthday will be later this year!");
            }
            else if (nowAge == age)
            {
                Console.WriteLine($"Hi {name}, you already had your birthday this year!");
            }
            else
            {
                Console.WriteLine($"Hi {name}, the entered age or year of birth is incorrect!");
            }
        }
    }
}