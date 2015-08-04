package Hamming;

use Carp;
use warnings;
use strict;
use Exporter;
use vars qw($VERSION @ISA @EXPORT @EXPORT_OK %EXPORT_TAGS);

$VERSION     = 1.00;
@ISA         = qw(Exporter);
@EXPORT      = ();
@EXPORT_OK   = qw(
    compute
);
%EXPORT_TAGS = ( DEFAULT => [qw(
    &compute
)],);


sub compute($$) {
    my $seq1 = shift(@_);
    my $seq2 = shift(@_);
    my $distance = 0;
 
    # Get the min length between the 2 sequences
    my $min_length = length($seq1) > length($seq2) ? length($seq2) : length($seq1);
    
    # Iterate over the min length and count the differences in the characters
    for(my $i = 0; $i < $min_length; $i++) {
        if (substr($seq1, $i, 1) ne substr($seq2, $i, 1)) {
            $distance++;
        }   
    }
    
    
    return $distance;
}