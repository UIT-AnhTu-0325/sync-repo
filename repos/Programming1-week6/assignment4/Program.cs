namespace assignment4
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Enter a text> ");
            string input = Console.ReadLine();

            SearchText(input, out var nrOfFullStops, out var nrOfCommas, out var nrOfSemiColons);
            Console.WriteLine($"result: {nrOfFullStops} full stops, {nrOfCommas} commas, {nrOfSemiColons} semicolons");
        }

        static void SearchText (string text, out int nrOfFullStops, out int nrOfCommas, out int nrOfSemiColons)
        {
            int countFullStops = 0;
            int countCommas = 0;
            int countSemiColons = 0;

            for (int i = 0; i < text.Length; i++)
            {
                if (text[i] == '.')
                {
                    countFullStops++;
                }
                if (text[i] == ',')
                {
                    countCommas++;
                }
                if (text[i] == ';')
                {
                    countSemiColons++;
                }
            }
            nrOfFullStops = countFullStops;
            nrOfCommas = countCommas;
            nrOfSemiColons = countSemiColons;
        }
    }
}