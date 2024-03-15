namespace assignment5
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int[] preSchooler = new int[10];
            int[] children = new int[10];
            int[] adult = new int[10];
            Console.Write("Enter age (0=stop): ");
            int input = int.Parse(Console.ReadLine());
            int indexPre = 0;
            int indexChild = 0;
            int indexAdult = 0;
            int sumPre = 0;
            int sumChild = 0;
            int sumAdult = 0;
            int oldestPre = int.MinValue;
            int oldestChild = int.MinValue;
            int oldestAdult = int.MinValue;

            while (input != 0)
            {
                if (input >= 1 && input <= 3)
                {
                    preSchooler[indexPre] = input;
                    indexPre++;
                }
                else if (input > 3 && input < 18)
                {
                    children[indexChild] = input;
                    indexChild++;
                }
                else
                {
                    adult[indexAdult] = input;
                    indexAdult++;
                }
                Console.Write("Enter age (0=stop): ");
                input = int.Parse(Console.ReadLine());
            }

            Console.WriteLine();
            Console.WriteLine("PRESCHOOLERS");
            for (int i = 0; i < indexPre; i++)
            {
                sumPre += preSchooler[i];
                if (preSchooler[i] > oldestPre)
                {
                    oldestPre = preSchooler[i];
                }
                Console.WriteLine($"Preschooler {i + 1} is {preSchooler[i]} years old.");
            }
            double avgPre = (double)sumPre / indexPre;
            Console.WriteLine($"Average preschooler is {avgPre.ToString("0.00")} years old");
            Console.WriteLine($"Oldest preschooler is: {oldestPre}");

            Console.WriteLine();
            Console.WriteLine("CHILDREN");
            for (int i = 0; i < indexChild; i++)
            {
                sumChild += children[i];
                if (children[i] > oldestChild)
                {
                    oldestChild = children[i];
                }
                Console.WriteLine($"Children {i + 1} is {children[i]} years old.");
            }
            double avgChild = (double)sumChild / indexChild;
            Console.WriteLine($"Average children is {avgChild.ToString("0.00")} years old");
            Console.WriteLine($"Oldest children is: {oldestChild}");

            Console.WriteLine();
            Console.WriteLine("ADULT");
            for (int i = 0; i < indexAdult; i++)
            {
                sumAdult += adult[i];
                if (adult[i] > oldestAdult)
                {
                    oldestAdult = adult[i];
                }
                Console.WriteLine($"Adult {i + 1} is {adult[i]} years old.");
            }
            double avgAdult = (double)sumAdult / indexAdult;
            Console.WriteLine($"Average adult is {avgAdult.ToString("0.00")} years old");
            Console.WriteLine($"Oldest adult is: {oldestAdult}");

        }
    }
}

