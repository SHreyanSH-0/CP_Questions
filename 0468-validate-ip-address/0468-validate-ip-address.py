from ipaddress import ip_address,IPv6Address
class Solution:
    def validIPAddress(self, queryIP: str) -> str:
        if queryIP.find('::')!=-1 :
            return "Neither"
        try:
            if type(ip_address(queryIP)) is IPv6Address:
                return "IPv6"
            else:
                return "IPv4"
        except:
            return "Neither"
        