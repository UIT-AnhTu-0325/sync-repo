namespace assignment7
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int[] dice = new int[6];
            Random random = new Random();

            for (int i = 0; i < 6; i++)
            {
                dice[i] = 0;
            }

            for (int i = 0; i < 6000; i++)
            {
                int value = random.Next(0, 6);
                dice[value]++;
            }

            for (int i = 0; i < 6; i++)
            {
                label1.Text += $"Number of throws of value {i + 1} = {dice[i]}\n";
            }
        }
    }
}