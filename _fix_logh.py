path = r'E:\Six\SixEngine\Editor\src\Log.h'
with open(path, 'rb') as f:
    data = f.read()

# Swap order: move enum before struct
old = (
    b"namespace SixEditor {\r\n"
    b"\tstruct SELogMessage {\r\n"
    b"\t\tSELogLevel level;\r\n"
    b"\t\tstd::string content;\r\n"
    b"\t\tstd::string category;\r\n"
    b"\t\tstd::string filename;\r\n"
    b"\t\tint line;\r\n"
    b"\t};\r\n"
    b"\tenum class SELogLevel {\r\n"
    b"\t\tDebug,\r\n"
    b"\t\tInfo,\r\n"
    b"\t\tWarning\r\n"
    b"\t};\r\n"
)
new = (
    b"namespace SixEditor {\r\n"
    b"\tenum class SELogLevel {\r\n"
    b"\t\tDebug,\r\n"
    b"\t\tInfo,\r\n"
    b"\t\tWarning\r\n"
    b"\t};\r\n"
    b"\tstruct SELogMessage {\r\n"
    b"\t\tSELogLevel level;\r\n"
    b"\t\tstd::string content;\r\n"
    b"\t\tstd::string category;\r\n"
    b"\t\tstd::string filename;\r\n"
    b"\t\tint line;\r\n"
    b"\t};\r\n"
)
n = data.count(old)
print('match:', n)
if n == 1:
    data = data.replace(old, new)
    with open(path, 'wb') as f:
        f.write(data)
    print('swapped')
else:
    print('NOT MATCHED')