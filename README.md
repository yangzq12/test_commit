add CodeNFT.sol file for simple ERC20 Token
Weird ERC20 Tokens
This repository contains minimal example implementations in Solidity of ERC20 tokens with behaviour that may be surprising or unexpected. All the tokens in this repo are based on real tokens, many of which have been used to exploit smart contract systems in the past. It is hoped that these example implementations will be of use to developers and auditors.

The ERC20 "specification" is so loosely defined that it amounts to little more than an interface declaration, and even the few semantic requirements that are imposed are routinely violated by token developers in the wild.

This makes building smart contracts that interface directly with ERC20 tokens challenging to say the least, and smart contract developers should in general default to the following patterns when interaction with external code is required:

A contract level allowlist of known good tokens.
Direct interaction with tokens should be performed in dedicated wrapper contracts at the edge of the system. This allows the core to assume a consistent and known good semantics for the behaviour of external assets.
In some cases the above patterns are not practical (for example in the case of a permissionless AMM, keeping an on chain allowlist would require the introduction of centralized control or a complex governance system), and in these cases developers must take great care to make these interactions in a highly defensive manner. It should be noted that even if an onchain allowlist is not feasible, an offchain allowlist in the official UI can also protect unsophisticated users from tokens that violate the contracts expectations, while still preserving contract level permissionlessness.
