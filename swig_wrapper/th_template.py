import %%MODULE_NAME%%

print("--- Testing SWIG-generated module: '%%MODULE_NAME%%' ---")

# Define test cases
%%TEST_CASES_DEFINITION%%

i = 0	
for (result, value) in test_cases.items():
    i += 1
    testdata = bytes(value)
    # Call the wrapped C function
    crc = %%MODULE_NAME%%.Crc8(testdata, 0xFF)
    crc ^= 0xFF
    print(f'CRC check {i}')
    print(f'CRC = {crc} (0x{crc:02X})')
    assert crc == result, "CRC check failed!"
    
print("--- All tests passed! ---")