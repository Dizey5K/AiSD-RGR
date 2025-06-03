#!/bin/bash

TESTS=(
    "test_empty_input"
    "test_repeated_words"
    "test_multiple_lines" 
    "test_special_chars"
    "test_empty_lines"
    "test_binary_data"
    "test_escape_chars"
    "test_long_word"
    "test_mixed_case"
    "test_brackets"
)

for test in "${TESTS[@]}"; do
    echo "──────────────────────────"
    echo "Testing: ${test#test_}"
    
    INPUT_FILE="tests/$test/input.txt"
    EXPECTED_FILE="tests/$test/expected_output.txt"
    ACTUAL_FILE="tests/$test/actual_output.txt"
    
    ./.crossref < "$INPUT_FILE" > "$ACTUAL_FILE"
    
    diff -w "$EXPECTED_FILE" "$ACTUAL_FILE"
    
    if [ $? -eq 0 ]; then
        echo "Passed"
    else
        echo "Failed"
    fi
done

echo "──────────────────────────"