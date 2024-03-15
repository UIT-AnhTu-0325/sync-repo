namespace assignment4
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.Write("1, 1");
            int pre1 = 1, pre2 = 1;
            int next;
            int count = 18;

            while (count > 0)
            {
                next = pre1 + pre2;
                Console.Write(", " + next);
                pre1 = pre2;
                pre2 = next;
                count--;
            }
        }
    }
}