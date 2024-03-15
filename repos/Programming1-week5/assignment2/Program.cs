namespace assignment2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int[] array = new int[20];
            Random random = new Random();
            int smallest = int.MaxValue;
            int count = 0;

            for (int i = 0; i < array.Length; i++)
            {
                array[i] = random.Next(0, 150);
                Console.WriteLine($"Element {i} = {array[i]}");
                if (array[i] < smallest)
                {
                    smallest = array[i];
                }
            }
            for (int i = 0; i < array.Length; i++)
            {
                if (array[i] == smallest)
                {
                    count++;
                }
            }
            
            Console.WriteLine();
            Console.WriteLine($"smallest number = {smallest}");
            Console.WriteLine($"number of occurence = {count}");
        }
    }
}