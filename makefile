CC = gcc
CFLAGS = -Wall
LDFLAGS = 
OBJFILES = main.o src/library.o src/login.o lib/admin/book.o lib/admin/user.o lib/common/common.o 
TARGET = lms

all: $(TARGET)

$(TARGET) : $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -f $(OBJFILES) *~