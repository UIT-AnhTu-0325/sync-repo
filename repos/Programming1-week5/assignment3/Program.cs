namespace assignment3
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Enter course name: ");
            string course = Console.ReadLine();
            Console.Write("Enter number of students: ");
            int student = int.Parse(Console.ReadLine());
            Console.WriteLine();
            int sum = 0;
            int highestGrade = int.MinValue;
            string highestStudent = string.Empty;

            string[] name = new string[student];
            int[] grade = new int[student];

            for (int i = 0; i < name.Length; i++)
            {
                Console.Write($"Enter name of student {i + 1}: ");
                name[i] = Console.ReadLine();
            }

            Console.WriteLine();
            for (int i = 0; i < grade.Length; i++)
            {
                Console.Write($"Enter grade of {name[i]}: ");
                grade[i] = int.Parse(Console.ReadLine());
                sum += grade[i];
                if (grade[i] > highestGrade)
                {
                    highestGrade = grade[i];
                    highestStudent = name[i];
                }
            }
            double avg = (double) sum / student;
            Console.WriteLine();
            Console.WriteLine($"Average grade: {avg.ToString("0.0")}");
            Console.WriteLine($"Student {highestStudent} has highest grade: {highestGrade}");
            Console.WriteLine();

            for (int i = 0; i < student; i++)
            {
                Console.WriteLine($"Grade for student {name[i]} (course {course}): {grade[i]}");
            }
        }
    }
}