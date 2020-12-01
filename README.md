# Project-1-Keylogger

Đây là kết quả nghiên cứu project môn Project 1 của sinh viên: Tạo một Keylogger đơn giản bằng C++.
- Họ và tên: Kiều Minh Hướng
- Mã số sinh viên: 20183928
- Khoa Công nghệ thông tin 03 - K63 - Đại học Bách Khoa Hà Nội
- Giảng viên hướng dẫn: thầy Phạm Huy Hoàng - Bộ môn Truyền thông & Mạng máy tính - Đại học Bách Khoa Hà Nội.
- Mã lớp học: 699557

- Keylogger có nhiệm vụ: Ghi nhận những phím người dùng nhập vào và lưu vào một file txt.
- Sử dụng CodeBlocks thêm một cờ mới trong Compiler Flag với tên là WindowsAPI và giá trị Compiler flags và Linker flags là -mwindows. Khi đó build chương trình thì dù tắt đi chương trình vẫn chạy ngầm và tự ghi nhận những kí tự người dùng nhập vào. Hoặc có lựa chọn khác là chạy trực tiếp Keylogger.exe đã được build sẵn. Tắt hoàn toàn bằng cách vào Details trong Task Manager, tìm đến Keylogger.exe và chọn End Task.
- Những công nghệ mới đã sử dụng trong project: WinAPI, hàm HOOK, các macro liên quan tới Keyboard, Virtual Key Code,...
- Những hướng phát triển tiếp theo của project: 
  + Hoàn thành nốt những phím đặc biệt như: F1..F12, Insert, PageUp, PageDown, NumLock, CapsLock,...
  + Keylogger này sẽ tự động chạy khi máy khởi động
  + Chuyển file txt sang một folder khác để người dùng không biết sự hiện diện của nó
  + Gửi file txt này về máy của kẻ tấn công thông qua giao thức chia sẻ file hoặc thông qua gửi email
