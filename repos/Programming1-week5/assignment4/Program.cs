namespace assignment4
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int[] array = new int[20];
            Console.Write("Enter a number (0=stop): ");
            int input = int.Parse(Console.ReadLine());
            int index = 0;
            int count = 0;

            while (input != 0 && index <= 19)
            {
                array[index] = input;
                index++;
                Console.Write("Enter a number (0=stop): ");
                input = int.Parse(Console.ReadLine());
            }

            Console.WriteLine();
            Console.Write("Enter a searchvalue: ");
            int value = int.Parse(Console.ReadLine());

            for (int i = 0; i < array.Length; i++)
            {
                if (array[i] == value)
                {
                    count++;
                }
            }
            Console.WriteLine();
            Console.WriteLine($"Number of occurences of searchvalue ({value}) is: {count}");
        }
    }
}