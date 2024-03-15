namespace assignment7
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            
        }
        private double Celsius2Kelvin(double degree)
        {
            return degree + 273;
        }
        private double Celsius2Fahrenheit(double degree)
        {
            return degree * 9 / 5 + 32;
        }
        private double Fahrenheit2Celsius(double degree)
        {
            return (degree - 32) * 5 / 9;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            double input = double.Parse(textBox1.Text);
            double output;
            if (radioButton1.Checked)
            {
                output = Celsius2Kelvin(input);
            }
            else if (radioButton2.Checked) {
                output = Celsius2Fahrenheit(input);
            }
            else
            {
                output = Fahrenheit2Celsius(input);
            }
            label4.Text = output.ToString("0.00");
        }
    }
}