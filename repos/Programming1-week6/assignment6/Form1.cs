namespace assignment6
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            int input = int.Parse(textBox1.Text);
            SquareByReferenceOut(input, out var square);
            label3.Text = square.ToString();
        }
        private void SquareByReferenceOut(int number, out int square)
        {
            int result = number * number;
            square = result;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            int number = int.Parse(textBox1.Text);
            var result = SquareByValue(number);
            label3.Text = result.ToString();
        }
        private int SquareByValue(int number)
        {
            return number * number;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int number = int.Parse(textBox1.Text);
            SquareByReference(ref number);
            label3.Text = number.ToString();
        }
        private void SquareByReference(ref int number)
        {
            number *= number;
        }
    }
}