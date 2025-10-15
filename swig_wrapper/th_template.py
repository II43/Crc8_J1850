import %%MODULE_NAME%%

print("--- Testing SWIG-generated module: '%%MODULE_NAME%%' ---")

# Call the wrapped C function
testdata= bytes([0xF2, 0x01, 0x83])
crc = %%MODULE_NAME%%.Crc8(testdata, 0xFF)
crc ^= 0xFF
print(f'CRC check 1')
print(f'CRC = {crc} (0x{crc:02X})')
assert crc == 0x37, "CRC check failed!"

print("--- All tests passed! ---")