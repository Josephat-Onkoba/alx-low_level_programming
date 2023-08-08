#include <elf.h>
#include "elf_utils.h"

/**
 * main - displays information contained in the ELF header of ELF file
 * @ac: number of arguments
 * @av: vector of arguments
 *     should be: program_name elf_filename
 *
 * Return: 0 if success
 */
int main(int ac, char **av)
{
	int fd, num_read, i;
	unsigned char *buff;
	Elf64_Ehdr head;

	if (ac != 2)
		dprintf(STDERR_FILENO, "Usage: elf_header elf_file\n"), exit(98);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]), exit(98);
	num_read = read(fd, &head, sizeof(Elf64_Ehdr));
	if (num_read == -1)
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]), exit(98);
	buff = head.e_ident;
	if (buff[0] == 0x7f && buff[1] == 'E' && buff[2] == 'L' && buff[3] == 'F')
	{
		printf("ELF Header:\n");
		printf("  Magic:   ");
		for (i = 0; i < 16; i++)
			printf("%02x ", buff[i]);
		printf("\n");
		printf("  Class:                             ");
		print_class(head.e_ident[4]);
		printf("  Data:                              ");
		print_data(head.e_ident[5]);
		printf("  Version:                           ");
		print_version(head.e_ident[6]);
		printf("  OS/ABI:                            ");
		print_obsabi(head.e_ident[7]);
		printf("  ABI Version:                       %u\n", head.e_ident[8]);
		printf("  Type:                              ");
		print_type(head.e_type);
		printf("  Entry point address:               %7p\n", (void *)head.e_entry);
	}
	else
		dprintf(STDERR_FILENO, "Error: Not an ELF file %s\n", av[1]), exit(98);
	if (close(fd) == -1)
		dprintf(STDERR_FILENO, "Error: Cannot close file %s\n", av[1]), exit(98);
	return (0);
}

/**
 * print_class - prints ELF class
 * @id: identifier to print
 */
void print_class(unsigned int id)
{
	switch (id)
	{
	case 1:
		printf("ELF32\n");
		break;
	case 2:
		printf("ELF64\n");
		break;
	default:
		printf("Invalid\n");
		break;
	}
}

/**
 * print_data - prints ELF data
 * @id: identifier to print
 */
void print_data(unsigned int id)
{
	switch (id)
	{
	case 1:
		printf("2's complement, little endian\n");
		break;
	case 2:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("Unknown\n");
		break;
	}
}

/**
 * print_version - prints ELF file version
 * @id: identifier to print
 */
void print_version(unsigned int id)
{
	if (id == 1)
		printf("1 (current)\n");
	else
		printf("Invalid\n");
}

/**
 * print_obsabi - prints ELF file OBS/ABI
 * @id: identifier to print
 */
void print_obsabi(unsigned int id)
{
	switch (id)
	{
	case 1:
		printf("UNIX - System V\n");
		break;
	case 2:
		printf("UNIX - HP-UX\n");
		break;
	case 3:
		printf("UNIX - NetBSD\n");
		break;
	case 4:
		printf("UNIX - Linux\n");
		break;
	case 5:
		printf("UNIX - Solaris\n");
		break;
	case 6:
		printf("UNIX - IRIX\n");
		break;
	case 7:
		printf("UNIX - FreeBSD\n");
		break;
	case 8:
		printf("UNIX - TRU64\n");
		break;
	case 9:
		printf("UNIX - ARM architecture\n");
		break;
	default:
		printf("UNIX - System V\n");
		break;
	}
}

/**
 * print_type - prints ELF file type
 * @id: identifier to print
 */
void print_type(unsigned int id)
{
	switch (id)
	{
	case 1:
		printf("REL (Relocatable file)\n");
		break;
	case 2:
		printf("EXEC (Executable file)\n");
		break;
	case 3:
		printf("DYN (Shared object file)\n");
		break;
	case 4:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("Unknown\n");
		break;
	}
}
