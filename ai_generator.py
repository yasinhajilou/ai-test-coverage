import os
from openai import OpenAI
from dotenv import load_dotenv

# Load environment variables
load_dotenv()

# Set OpenAI API key
client = OpenAI(
    api_key=os.environ.get("OPENAI_API_KEY"),
)

def read_c_program(file_path):
    """Reads the content of a file."""
    with open(file_path, 'r') as file:
        return file.read()

def generate_missing_unit_tests(c_program_code, c_test_code):
    """
    Generates missing unit tests using OpenAI.
    """
    prompt = (
        "Here is a C program:\n\n" + c_program_code +
        "\n\nHere are the existing unit tests for the C program:\n\n" + c_test_code +
        "\n\nIdentify the missing unit tests for the C program's functions. Generate the missing unit tests as C code + whole necessary includes code to run it. No explanations just comments on code and output just the code.(without any code block delimiters and include the line '#include \"../calculator.h\"')"
    )


    # Send request to OpenAI API
    response = client.chat.completions.create(
        model="gpt-4o-mini",
        messages=[
            {"role": "system", "content": "You are a helpful assistant."},
            {"role": "user", "content": prompt}
        ]
    )

    return response.choices[0].message.content

# File paths for the C program and its test file
c_program_path = "./calculator.c"
c_test_path = "./test_calculator.c"

# Read the C program code and the test file
c_program_code = read_c_program(c_program_path)
c_test_code = read_c_program(c_test_path)

# Generate missing unit tests
generated_tests = generate_missing_unit_tests(c_program_code, c_test_code)

# Save the generated unit tests
output_file = "generated_tests/test_calculator_missing.c"
os.makedirs(os.path.dirname(output_file), exist_ok=True)

with open(output_file, "w") as test_file:
    test_file.write(generated_tests)

print(f"Missing tests generated and saved in '{output_file}'")
