namespace Array
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Enter a number: ");
            int input = int.Parse(Console.ReadLine());
            int[] array = new int[input];
            int highestNumber = int.MinValue;
            int lowestNumber = int.MaxValue;

            for (int i = 0; i < array.Length; i++)
            {
                Console.Write($"Enter number {i + 1}: ");
                array[i] = int.Parse(Console.ReadLine());

                if (array[i] > highestNumber)
                {
                    highestNumber = array[i];
                }
                if (array[i] < lowestNumber)
                {
                    lowestNumber = array[i];
                }
            }
            Console.WriteLine($"Highest number is {highestNumber}");
            Console.WriteLine($"Lowest number is {lowestNumber}");
        }
    }
}