namespace assignment3
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Enter number of seconds: ");
            int second = int.Parse(Console.ReadLine());
            int minute = (second / 60);
            second = (second % 60);
            int hour = (minute / 60);
            minute = (minute % 60);

            Console.WriteLine(string.Format("{0:00}:{1:00}:{2:00}", hour, minute, second));
        }
    }
}