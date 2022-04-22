# IPv6

address = input().split(':')
addr_len = len(address)

new_address = []
# 생략이 1개 이하
if addr_len == 8:
    for addr in address:
        if len(addr)!=4:
            new_addr = (4-len(addr))*'0'+addr
            new_address.append(new_addr)
        else:
            new_address.append(addr)
# 생략이 2개 이상
else:
    if address[0] == '':
        addr_cnt = addr_len - 2  # 존재하는 주소 partition 개수
        for k in range(8-addr_cnt):
            new_address.append('0000')
        for i in range(2, 2+addr_cnt):
            if len(address[i])!=4:
                new_addr = (4 - len(address[i])) * '0' + address[i]
                new_address.append(new_addr)
            else:
                new_address.append(address[i])
    elif address[-1] == '':
        addr_cnt = addr_len - 2  # 존재하는 주소 partition 개수
        for i in range(addr_cnt):
            if len(address[i])!=4:
                new_addr = (4 - len(address[i])) * '0' + address[i]
                new_address.append(new_addr)
            else:
                new_address.append(address[i])
        for k in range(8-addr_cnt):
            new_address.append('0000')
    else:
        addr_cnt = addr_len - 1  # 존재하는 주소 partition 개수
        for addr in address:
            if addr!='':
                if len(addr) != 4:
                    new_addr = (4 - len(addr)) * '0' + addr
                    new_address.append(new_addr)
                else:
                    new_address.append(addr)
            else:
                for i in range(8-addr_cnt):
                    new_address.append('0000')

answer = ':'.join(new_address)
print(answer)