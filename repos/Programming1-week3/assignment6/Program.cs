namespace assignment6
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Enter score: ");
            int input = int.Parse(Console.ReadLine());
            string grade;

            switch (input / 10)
            {
                case 10:
                    grade = "A";
                    break;
                case 9:
                    grade = "A";
                    break;
                case 8:
                    grade = "B";
                    break;
                case 7:
                    grade = "C";
                    break;
                case 6:
                    grade = "D";
                    break;
                default:
                    grade = "F";
                    break;
            }

            Console.WriteLine();
            Console.WriteLine("grade: " + grade);
            if (grade == "A" || grade == "B" || 
                grade == "C" || grade == "D") 
            {
                Console.WriteLine("course passed");
            }
            else
            {
                Console.WriteLine("course not passed");
            }
        }
    }
}