package Grains;

use Scalar::Util;
use bigint;
use Math::BigInt;
use warnings;
use strict;
use Exporter;
use vars qw($VERSION @ISA @EXPORT @EXPORT_OK %EXPORT_TAGS);

$VERSION     = 1.00;
@ISA         = qw(Exporter);
@EXPORT      = ();
@EXPORT_OK   = qw(
    square
    total
);
%EXPORT_TAGS = ( DEFAULT => [qw(
    &square
    &total
)],);

sub square($)
{
    my $square_num = shift(@_);
    
    if (!Scalar::Util::looks_like_number($square_num)) {
        croak("Input square $square_num is not a number!\n");
    }
    
    if ($square_num < 1) {
        croak("Input square $square_num cannot be less than 1");
    }
    
    return 2**($square_num - 1);
}

sub total()
{
    return 2 ** 64;
}

