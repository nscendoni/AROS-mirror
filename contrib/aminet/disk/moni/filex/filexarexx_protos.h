/* Prototypes for functions defined in
filexarexx.c
 */

extern void (* ARexxResultHook)(struct RexxHost * , struct RexxMsg * );

void ReplyRexxCommand(struct RexxMsg * , long , long , char * );

void FreeRexxCommand(struct RexxMsg * );

struct RexxMsg * CreateRexxCommand(struct RexxHost * , char * , BPTR );

struct RexxMsg * CommandToRexx(struct RexxHost * , struct RexxMsg * );

struct RexxMsg * SendRexxCommand(struct RexxHost * , char * , BPTR );

void CloseDownARexxHost(struct RexxHost * );

struct RexxHost * SetupARexxHost(char * , struct MsgPort * );

struct rxs_command * FindRXCommand(char * );

char * StrDup(char * );

void ARexxDispatch(struct RexxHost * );

void DoShellCommand(struct RexxHost * , char * , BPTR );

void CloseCommandShell(void);

void DoCommandShellMsg(void);

BOOL OpenCommandShell(void);

