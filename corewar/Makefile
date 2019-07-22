VM_NAME = corewar
VM = vm
ASM_NAME = asm
ASM = assembler
LIBFT=libft
LIBFT_A=libft/libft.a


all: $(VM_NAME) $(ASM_NAME)

$(LIBFT_A):
	@make -C $(LIBFT)

$(VM_NAME): $(LIBFT_A)
	@make -C $(VM)
$(ASM_NAME): $(LIBFT_A)
	@make -C $(ASM)

clean:
	@make -C $(LIBFT) $@
	@make -C $(VM) $@
	@make -C $(ASM) $@

fclean: clean
	@make -C $(LIBFT) $@
	@make -C $(VM) $@
	@make -C $(ASM) $@
	@/bin/rm -f $(VM_NAME)
	@/bin/rm -f $(ASM_NAME)

.PHONY: clean fclean re

re: fclean all
