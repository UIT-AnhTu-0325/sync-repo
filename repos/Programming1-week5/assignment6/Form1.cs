namespace assignment6
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        int[] array = new int[20];
        private void button1_Click(object sender, EventArgs e)
        {
            label4.Text = string.Empty;
            int input = int.Parse(textBox1.Text);

            for (int i = 0; i < array.Length; i++)
            {
                if (array[i] == input || array[i] > input)
                {
                    label4.Text += $"Element {i} = {array[i] + 10}\n";
                }
                else
                {
                    label4.Text += $"Element {i} = {array[i] - 5}\n";
                }
            }
            button1.Enabled = false;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            Random random = new Random();

            for (int i = 0; i < array.Length; i++)
            {
                array[i] = random.Next(0, 501);
                label3.Text += $"Element {i} = {array[i]}\n";
            }
        }
    }
}