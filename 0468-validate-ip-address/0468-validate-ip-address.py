class Solution:

    def isIpv6(self, queryIP):
        v = queryIP.split('::')

        if len(v) >= 2:
            return False
        if(len(v) == 0):
            v = queryIp
        n = 0
        for s in v:
            hold = s.split(':')
            n = n + len(hold)
            for p in hold:
                if len(p) > 4 or len(p) == 0: return False
                for c in p:
                    if not ((c >= 'a' and c <= 'f') or (c >= '0' and c <= '9')or (c >= 'A' and c <= 'F')):
                        return False

        if n > 8: return False
        return True

    def isIPv4(self, s):
        v = s.split('.')
        if len(v) != 4 : 
            return False
        
        for val in v:
            if len(val) == 0:
                return False
            for c in val:
                if not (c >= '0' and c <= '9'): return False
            if int(val) > 255 or int(val) < 0:
                return False
            if val[0] == '0' and len(val) > 1:
                return False
        
        return True


    def validIPAddress(self, queryIP: str) -> str:
        if self.isIpv6(queryIP) is True:
            return "IPv6"
        if self.isIPv4(queryIP) is True:
            return "IPv4"
        return "Neither"
        