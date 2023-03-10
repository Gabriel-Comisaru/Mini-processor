# Mini Processor

The program is an implementation of a bit interpreter similar the the one of a processor. It is capable of decoding and executing simple instructions such as addition, substraction, multiplication, and division.

At the most basic level, information is stored in the form of bits. For a processor, this information is divided into two categories: instructions and data. Esentially, given a sequence of bits, the processor decodes the instruction and then executes it.

An instrution has the following format:

![image](https://user-images.githubusercontent.com/94917043/224436868-4805cb25-bee0-43ba-a2dd-17d7bca0aa0b.png)

- N represents the number of instructions to be executed; this is represented on 3 bits and it is obtained by converting the value of the most semnificative 3 bits from binary in decimal and adding 1.

- Op represents the code of an instructions and it is represented on 2 bits. Op can be +, -, * or /

- Dim represents the dimension of an operand and it is represented on 4 bits.

For the first task we will be reading from standard input a number of type unsigned int which contains the instruction which we will be decoding. As a result, N, the operators and the dimensiun of the operands will pe printed to standard output.

For the second task we will continue the first and we'll read the operands and execute them.

### Built with

* [![Next][C]][Next-url]

<p align="right">(<a href="#readme-top">back to top</a>)</p>
