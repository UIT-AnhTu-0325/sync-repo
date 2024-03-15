namespace assignment5
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            double num1 = double.Parse(textBox1.Text);
            double num2 = double.Parse(textBox2.Text);
            var result = AddNumber(num1, num2);
            label4.Text = result.ToString("0.###");
        }
        private double AddNumber(double num1, double num2)
        {
            return num1 + num2;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            double num1 = double.Parse(textBox1.Text);
            double num2 = double.Parse(textBox2.Text);
            var result = SubtractNumber(num1, num2);
            label4.Text = result.ToString("0.###");
        }
        private double SubtractNumber(double num1, double num2)
        {
            return num1 - num2;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            double num1 = double.Parse(textBox1.Text);
            double num2 = double.Parse(textBox2.Text);
            var result = MultiplyNumber(num1, num2);
            label4.Text = result.ToString("0.###");
        }
        private double MultiplyNumber(double num1, double num2)
        {
            return num1 * num2;
        }

        private void button4_Click(object sender, EventArgs e)
        {
            double num1 = double.Parse(textBox1.Text);
            double num2 = double.Parse(textBox2.Text);
            var result = DivideNumber(num1, num2);
            label4.Text = result.ToString("0.###");
        }
        private double DivideNumber(double num1, double num2)
        {
            return num1 / num2;
        }
    }
}